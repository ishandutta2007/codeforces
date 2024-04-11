#include <iostream>
#include <iomanip>

using namespace std;

typedef long double ld;

int l[6];
int r[6];

ld pg(int i, int x){//suurempi kuin tai yhtsuuri
    if (x>r[i]) return 0;
    if (x<l[i]) return 1;
    return (ld)(r[i]-x+1)/(ld)(r[i]-l[i]+1);
}

ld pe(int i, int x){
    if (x>r[i]) return 0;
    if (x<l[i]) return 0;
    return (ld)1/(ld)(r[i]-l[i]+1);
}

int main(){
    int n;
    cin>>n;
    for (int i=0;i<n;i++){
        cin>>l[i]>>r[i];
    }
    ld v=0;
    for (int w=0;w<n;w++){
        for (int i=0;i<(1<<n);i++){
            int ok=0;
            for (int ii=0;ii<n;ii++){
                if ((1<<ii)&i){
                    ok=1;
                    if (ii==w){
                        ok=0;
                        break;
                    }
                }
            }
            if (ok){
                for (int ii=0;ii<=r[w];ii++){
                    ld p=pg(w, ii+1);
                    for (int iii=0;iii<n;iii++){
                        if (iii!=w){
                            if ((1<<iii)&i){
                                p*=pe(iii, ii);
                            }
                            else{
                                p*=(1-pg(iii, ii));
                            }
                        }
                    }
                    v+=(ld)ii*p;
                }
            }
        }
    }
    for (int i=0;i<(1<<n);i++){
        int ok=0;
        for (int ii=0;ii<n;ii++){
            if ((1<<ii)&i){
                ok++;
            }
        }
        if (ok>1){
            for (int ii=0;ii<=10000;ii++){
                ld p=1;
                for (int iii=0;iii<n;iii++){
                    if ((1<<iii)&i){
                        p*=pe(iii, ii);
                    }
                    else{
                        p*=(1-pg(iii, ii));
                    }
                }
                v+=(ld)ii*p;
            }
        }
    }
    cout<<setprecision(15)<<v<<endl;
}
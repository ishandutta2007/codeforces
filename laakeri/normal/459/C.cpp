#include <iostream>

using namespace std;

int s[1002][1002];
int ss[1002][1002];

int main(){
    int n,d,k;
    cin>>n>>k>>d;
    for (int i=0;i<1001;i++){
        s[0][i]=1;
    }
    ss[0][0]=n;
    int y=0;
    for (int i=0;i<d;i++){
        int me=0;
        for (int ii=0;ii<n;ii++){
            if (ss[i][ii]){
                int e=ss[i][ii]/k;
                int es=ss[i][ii]%k;
                if (es) e++;
                me=max(e,me);
                int et=e;
                int kk=1;
                int nss=1;
                for (int iii=ii;iii<ii+ss[i][ii];iii++){
                    if (nss){
                        ss[i+1][iii]=et;
                        nss=0;
                    }
                    s[i+1][iii]=kk;
                    et--;
                    if (et==0){
                        es--;
                        if (es==0){
                            e--;
                        }
                        et=e;
                        kk++;
                        nss=1;
                    }
                }
            }
        }
        if (me==1){
            y=1;
        }
    }
    if (y){
        for (int i=1;i<=d;i++){
            for (int ii=0;ii<n;ii++){
                cout<<s[i][ii]<<" ";
            }
            cout<<endl;
        }
    }
    else{
        cout<<-1<<endl;
    }
}
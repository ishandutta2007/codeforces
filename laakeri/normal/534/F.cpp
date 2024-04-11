#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;

char dp[22][170001][1<<5];
char f[22][170001][1<<5];
int aa[30];
int bb[30];

int dif[40][40][10];
int val[170001][10];
vector<int> ps[10];

char v[30][30];

const int base=11;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    for (int i=0;i<n;i++){
        cin>>aa[i];
    }
    for (int i=0;i<m;i++){
        cin>>bb[i];
    }
    for (int i=0;i<(1<<n);i++){
        int bl=0;
        int c=0;
        for (int ii=0;ii<n;ii++){
            if ((1<<ii)&i){
                if (bl==0){
                    bl=1;
                    c++;
                }
            }
            else{
                bl=0;
            }
        }
        ps[c].push_back(i);
    }
    for (int i=0;i<(1<<n);i++){
        for (int ii=0;ii<(1<<n);ii++){
            for (int iii=0;iii<n;iii++){
                if ((i&(1<<iii))==0&&(ii&(1<<iii))>0){
                    dif[i][ii][iii]++;
                }
            }
        }
    }
    for (int i=0;i<170000;i++){
        int x=i;
        for (int ii=0;ii<5;ii++){
            val[i][ii]=x%base;
            x/=base;
        }
    }
    dp[0][0][0]=1;
    for (int i=0;i<m;i++){
        for (int ii=0;ii<170000;ii++){
            for (int iii=0;iii<(1<<n);iii++){
                if (dp[i][ii][iii]){
                    vector<int> nv(n);
                    for (int j=0;j<n;j++){
                        nv[j]=val[ii][j];
                    }
                    for (int j=0;j<(int)ps[bb[i]].size();j++){
                        int bm=ps[bb[i]][j];
                        int ok=1;
                        for (int jj=0;jj<n;jj++){
                            nv[jj]+=dif[iii][bm][jj];
                            if (nv[jj]>aa[jj]){
                                ok=0;
                            }
                        }
                        if (ok){
                            int ne=0;
                            for (int jj=n-1;jj>=0;jj--){
                                ne*=base;
                                ne+=nv[jj];
                            }
                            dp[i+1][ne][bm]=1;
                            f[i+1][ne][bm]=iii;
                        }
                        for (int jj=0;jj<n;jj++){
                            nv[jj]-=dif[iii][bm][jj];
                        }
                    }
                }
            }
        }
    }
    int asd=0;
    int kj=0;
    for (int i=n-1;i>=0;i--){
        asd*=base;
        asd+=aa[i];
    }
    for (int i=0;i<(1<<n);i++){
        if (dp[m][asd][i]){
            kj=i;
        }
    }
    for (int i=m;i>0;i--){
        //cout<<i<<" "<<asd<<" "<<kj<<endl;
        for (int ii=0;ii<n;ii++){
            if (kj&(1<<ii)){
                v[ii][i-1]='*';
            }
            else{
                v[ii][i-1]='.';
            }
        }
        int ne=f[i][asd][kj];
        int ke=1;
        for (int jj=0;jj<n;jj++){
            asd-=dif[ne][kj][jj]*ke;
            ke*=base;
        }
        kj=ne;
    }
    for (int i=0;i<n;i++){
        for (int ii=0;ii<m;ii++){
            cout<<v[i][ii];
        }
        cout<<endl;
    }
}
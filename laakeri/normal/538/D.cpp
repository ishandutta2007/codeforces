#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;

int ok[155][155];
string s[55];
string v[155];
int fo[55][55];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    for (int i=0;i<n;i++){
        cin>>s[i];
    }
    for (int i=-n;i<=n;i++){
        for (int ii=-n;ii<=n;ii++){
            int f=0;
            int ff=0;
            for (int j=0;j<n;j++){
                for (int jj=0;jj<n;jj++){
                    if (s[j][jj]=='o'){
                        if (j+i>=0&&j+i<n&&jj+ii>=0&&jj+ii<n){
                            if (s[j+i][jj+ii]=='x'){
                                ff=1;
                            }
                            if (s[j+i][jj+ii]=='.'){
                                f=1;
                            }
                        }
                    }
                    if (f) break;
                }
                if (f) break;
            }
            if (f==0&&ff==1){
                ok[i+n][ii+n]=1;
                for (int j=0;j<n;j++){
                    for (int jj=0;jj<n;jj++){
                        if (s[j][jj]=='o'){
                            if (j+i>=0&&j+i<n&&jj+ii>=0&&jj+ii<n){
                                fo[j+i][jj+ii]=1;
                            }
                        }
                        if (f) break;
                    }
                    if (f) break;
                }
            }
        }
    }
    for (int i=0;i<n;i++){
        for (int ii=0;ii<n;ii++){
            if (s[i][ii]=='x'&&fo[i][ii]==0){
                cout<<"NO"<<endl;
                return 0;
            }
        }
    }
    cout<<"YES"<<endl;
    for (int i=1;i<2*n;i++){
        for (int ii=1;ii<2*n;ii++){
            if (i==n&&ii==n){
                v[i]+='o';
            }
            else if (ok[i][ii]){
                v[i]+='x';
            }
            else{
                v[i]+='.';
            }
        }
        cout<<v[i]<<endl;
    }
}
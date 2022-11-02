#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;

string s[55];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    int v=0;
    for (int i=0;i<n;i++){
        cin>>s[i];
    }
    for (int i=0;i<n-1;i++){
        for (int ii=0;ii<m-1;ii++){
            int f=0;
            int a=0;
            int c=0;
            int e=0;
            for (int j=0;j<2;j++){
                for (int jj=0;jj<2;jj++){
                    if (s[i+j][ii+jj]=='f') f=1;
                    if (s[i+j][ii+jj]=='a') a=1;
                    if (s[i+j][ii+jj]=='c') c=1;
                    if (s[i+j][ii+jj]=='e') e=1;
                }
            }
            if (f==1&&a==1&&c==1&&e==1){
                v++;
            }
        }
    }
    cout<<v<<endl;
}
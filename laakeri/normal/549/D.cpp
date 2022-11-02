#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;

string s[111];
int a[111][111];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    for (int i=0;i<n;i++){
        cin>>s[i];
    }
    int v=0;
    for (int i=n-1;i>=0;i--){
        for (int ii=m-1;ii>=0;ii--){
            if (s[i][ii]=='W'&&a[i][ii]!=1){
                v++;
                int d=1-a[i][ii];
                for (int j=0;j<=i;j++){
                    for (int jj=0;jj<=ii;jj++){
                        a[j][jj]+=d;
                    }
                }
            }
            if (s[i][ii]=='B'&&a[i][ii]!=-1){
                v++;
                int d=-1-a[i][ii];
                for (int j=0;j<=i;j++){
                    for (int jj=0;jj<=ii;jj++){
                        a[j][jj]+=d;
                    }
                }
            }
        }
    }
    cout<<v<<endl;
}
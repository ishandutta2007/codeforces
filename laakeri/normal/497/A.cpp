#include <iostream>

using namespace std;

int r[1001];

int eq[1001];

string s[1001];

int n,m;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for (int i=0;i<n;i++){
        cin>>s[i];
        eq[i]=1;
    }
    int v=0;
    for (int i=0;i<m;i++){
        int f=0;
        for (int ii=0;ii<n-1;ii++){
            if (eq[ii]){
                if (s[ii][i]>s[ii+1][i]){
                    f=1;
                    break;
                }
            }
        }
        v+=f;
        if (!f){
            for (int ii=0;ii<n-1;ii++){
                if (eq[ii]){
                    if (s[ii][i]<s[ii+1][i]){
                        eq[ii]=0;
                    }
                }
            }
        }
    }
    cout<<v<<endl;
}
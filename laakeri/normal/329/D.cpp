#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;

string v[111];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,x;
    cin>>n>>x;
    if (n<=5){
        for (int i=0;i<n;i++){
            v[i]=string(n, '.');
            if (i%2==0){
                for (int ii=0;ii<n/2;ii++){
                    v[i][ii]='>';
                }
                for (int ii=n/2+1;ii<n-1;ii+=2){
                    v[i][ii]='>';
                }
                v[i][n-1]='v';
            }
            else{
                for (int ii=0;ii<n/2;ii++){
                    v[i][n-1-ii]='<';
                }
                for (int ii=n/2+1;ii<n-1;ii+=2){
                    v[i][n-1-ii]='<';
                }
                v[i][0]='v';
            }
        }
    }
    else{
        for (int i=0;i<n;i++){
            v[i]=string(n, '.');
            if (i%2==0){
                if (i==0){
                    for (int ii=0;ii<n/2;ii++){
                        v[i][ii]='>';
                    }
                    for (int ii=n/2+1;ii<n-1;ii+=2){
                        v[i][ii]='>';
                    }
                    v[i][n-1]='v';
                }
                else{
                    for (int ii=1;ii<n/2;ii++){
                        v[i][ii]='>';
                    }
                    for (int ii=n/2+1;ii<n-1;ii+=2){
                        v[i][ii]='>';
                    }
                    v[i][n-1]='v';
                }
            }
            else{
                for (int ii=0;ii<n/2;ii++){
                    v[i][n-1-ii]='<';
                }
                for (int ii=n/2+1;ii<n-2;ii+=2){
                    v[i][n-1-ii]='<';
                }
                if (i<n-1) v[i][1]='v';
                else v[i][1]='<';
            }
        }
        for (int i=1;i<n;i++){
            v[i][0]='^';
        }
    }
    for (int i=0;i<n;i++){
        cout<<v[i]<<'\n';
    }
    cout<<1<<" "<<1<<endl;
}
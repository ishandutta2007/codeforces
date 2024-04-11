#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef long double ld;

int a[505050];
int u[505050];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>a[i];
    }
    a[0]=a[1];
    a[n+1]=a[n];
    int mu=0;
    int tu=0;
    for (int i=1;i<=n;i++){
        if (a[i]!=a[i-1]&&a[i]!=a[i+1]){
            u[i]=1;
            tu++;
        }
        else{
            tu=0;
        }
        mu=max(mu, tu);
    }
    if (mu==0){
        cout<<0<<endl;
    }
    else if(mu<3){
        cout<<1<<endl;
    }
    else{
        cout<<mu/2+(mu%2)<<endl;
    }
    tu=0;
    int ts=0;
    for (int i=1;i<=n;i++){
        if (a[i]!=a[i-1]&&a[i]!=a[i+1]){
            u[i]=1;
            tu++;
        }
        else{
            if (tu>0){
                if (a[ts-1]==a[i]){
                    for (int j=ts;j<i;j++){
                        a[j]=a[ts-1];
                    }
                }
                else{
                    for (int j=ts;j<ts+tu/2;j++){
                        a[j]=a[ts-1];
                    }
                    for (int j=ts+tu/2;j<i;j++){
                        a[j]=a[i];
                    }
                }
            }
            tu=0;
            ts=i+1;
        }
    }
    for (int i=1;i<=n;i++){
        cout<<a[i]<<" ";
    }
}
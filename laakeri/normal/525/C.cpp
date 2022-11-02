#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;

int lol[1010101];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    for (int i=0;i<n;i++){
        int a;
        cin>>a;
        lol[a]++;
    }
    ll v=0;
    for (int i=1000000;i>=0;i--){
        int f=1;
        while (lol[i]+lol[i+1]>1&&f==1){
            f=0;
            int h=min(2, lol[i+1]);
            lol[i+1]-=h;
            lol[i]-=2-h;
            for (int ii=i;ii>=0;ii--){
                if (lol[ii]+lol[ii+1]>1){
                    f=1;
                    int h=min(2, lol[ii+1]);
                    lol[ii+1]-=h;
                    lol[ii]-=2-h;
                    v+=(ll)i*(ll)ii;
                    break;
                }
            }
        }
    }
    cout<<v<<endl;
}
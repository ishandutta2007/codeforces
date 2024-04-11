#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;

int has[909000];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    int ma=0;
    for (int i=0;i<n;i++){
        int a;
        cin>>a;
        has[a]++;
        ma=max(ma, a);
    }
    int f=1;
    int v=0;
    while (f){
        f=0;
        for (int i=1;i<=ma;i++){
            if (has[i]>1){
                has[i]--;
                has[i+1]++;
                f=1;
                ma=max(ma, i+1);
                v++;
            }
        }
    }
    cout<<v<<endl;
}
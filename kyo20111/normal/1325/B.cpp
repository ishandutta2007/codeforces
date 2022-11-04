#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define all(x) (x).begin(), (x).end()

int t, n;
int main(){
    scanf("%d",&t);
    while(t--){
        set<int> s;
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            int a; scanf("%d",&a);
            s.insert(a);
        }
        printf("%d\n",s.size());
    }
}
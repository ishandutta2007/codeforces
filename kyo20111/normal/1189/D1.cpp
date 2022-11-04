#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
vector<int> v[101010];
int main(){
    scanf("%d",&n);
    for(int i=1;i<n;i++){
        int a,b; scanf("%d %d",&a,&b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for(int i=1;i<=n;i++) if(v[i].size() == 2) return !printf("NO");
    printf("YES");
}
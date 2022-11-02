#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <utility>

using namespace std;

#define For(i,n) for(i=0;i<(n);i++)

void solve(int n){
    int i,k;
    pair<int,int> a[111],t;
    vector<pair<int,int>> ans;
    scanf("%d",&k);
    For(i,n){
        scanf("%d",&a[i].first);
        a[i].second=i+1;
    }
    sort(a,a+n);
    i=0;
    while(i<k&&(a[n-1].first-a[0].first>1)){
        a[0].first++;
        a[n-1].first--;
        t.first=a[n-1].second;
        t.second=a[0].second;
        ans.push_back(t);
        sort(a,a+n);
        i++;
    }
    printf("%d %d\n",a[n-1].first-a[0].first,i);
    For(i,ans.size()){
        printf("%d %d\n",ans[i].first,ans[i].second);
    }
}


int main() {
#pragma comment(linker, "/STACK:268435456")
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n;
    while(scanf("%d",&n)!=EOF){
        solve(n);
    }
    return 0;
}
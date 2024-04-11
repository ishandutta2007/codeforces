#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int n;
int a[N];
multiset<int> s;
int ans=0;
int b[N];
int main(){
    scanf("%d",&n);
    long long sum=0;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        s.insert(a[i]);sum+=a[i];
    }
    multiset<int>::iterator it;
    for(int i=1;i<=n;i++){
        s.erase(s.find(a[i]));
        it=s.end();it--;
        if(2*(*it)==sum-a[i]) b[++ans]=i;
        s.insert(a[i]);
    }
    printf("%d\n",ans);
    for(int i=1;i<=ans;i++) printf("%d ",b[i]);
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
int n;
vector<pair<int,int>> a;
vector<int> m;
vector<tuple<int,int,int>> ans;

int main(){
    scanf("%d",&n);
    a.resize(n);m.resize(n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i-1].first);
        a[i-1].second=i;
    }
    for(int i=1;i<=n;i++){
        scanf("%d",&m[i-1]);
    }
    sort(a.begin(),a.end());
    sort(m.begin(),m.end());
    vector<pair<int,int>> st;
    int pt=0;
    for(int i=0;i<n;i++){
        while(a[pt].first<m[i]&&pt<n){
            st.push_back(a[pt]);
            pt++;
        }
        if(pt==n)return !printf("NO");
        if(a[pt].first==m[i]){
            pt++;
            continue;
        }
        if(st.empty())return !printf("NO");
        pair<int,int> top=st.back();
        if(m[i]-top.first<=a[pt].first-m[i]){
            st.pop_back();
            a[pt].first-=(m[i]-top.first);
            ans.push_back(make_tuple(top.second,a[pt].second,m[i]-top.first));
        }
        else{
            st.back().first+=(a[pt].first-m[i]);
            ans.push_back(make_tuple(top.second,a[pt].second,a[pt].first-m[i]));
            pt++;
        }
    }
    if(!st.empty())return !printf("NO");
    printf("YES\n%d\n",ans.size());
    for(tuple<int,int,int> i:ans){
        printf("%d %d %d\n",get<0>(i),get<1>(i),get<2>(i));
    }

}
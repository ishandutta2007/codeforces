#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main(){
    int n,v;
    vector<pair<int,int> > points;
    scanf("%lld",&n);
    for (int x = 0; x<n; x++){
        int a,b;
        scanf("%lld%lld",&a,&b);
        points.push_back({a, b});
    }
scanf("%lld", &v);
    for (int x = 0; x<n; x++){
int a = points[x].first, b = points[x].second;
        points[x] = {v*b-a,v*b+a};
}

    sort(points.begin(),points.end());
    vector<int> lis;
    for (auto x : points){
        if (lis.empty() || x.second>=lis.back()) lis.push_back(x.second);
        else *upper_bound(lis.begin(),lis.end(),x.second) = x.second;
    }
    int ans2 = lis.size();
    lis.clear();
    points.push_back({0,0});
    sort(points.begin(),points.end());
    for (auto x : points){
        if (x.first<0 || x.second<0) continue;
        if (lis.empty() || x.second>=lis.back()) lis.push_back(x.second);
        else *upper_bound(lis.begin(),lis.end(),x.second) = x.second;
    }
    printf("%lld %lld",(int)lis.size()-1,ans2);
return 0;
}
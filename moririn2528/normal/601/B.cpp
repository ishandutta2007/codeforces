#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<cmath>
#include<algorithm>
#include<map>
#include<queue>
#include<deque>
#include<iomanip>
#include<tuple>
#include<cassert>
#include<set>
#include<complex>
#include<numeric>
#include<functional>
using namespace std;
typedef long long int LL;
typedef pair<int,int> P;
typedef pair<LL,int> LP;
const int INF=1<<30;
const LL MAX=1e9+7;

void array_show(int *array,int array_n,char middle=' '){
    for(int i=0;i<array_n;i++)printf("%d%c",array[i],(i!=array_n-1?middle:'\n'));
}
void array_show(LL *array,int array_n,char middle=' '){
    for(int i=0;i<array_n;i++)printf("%lld%c",array[i],(i!=array_n-1?middle:'\n'));
}
void array_show(vector<int> &vec_s,int vec_n=-1,char middle=' '){
    if(vec_n==-1)vec_n=vec_s.size();
    for(int i=0;i<vec_n;i++)printf("%d%c",vec_s[i],(i!=vec_n-1?middle:'\n'));
}
void array_show(vector<LL> &vec_s,int vec_n=-1,char middle=' '){
    if(vec_n==-1)vec_n=vec_s.size();
    for(int i=0;i<vec_n;i++)printf("%lld%c",vec_s[i],(i!=vec_n-1?middle:'\n'));
}


int main(){
    int n,m;
    int i,j,k;
    LL a,b,c,d;
    vector<LL> v1,v2,vl,vr;
    priority_queue<P> q1;
    cin>>n>>m;
    cin>>b;
    for(i=0;i<n-1;i++){
        cin>>a;
        q1.push(make_pair(abs(a-b),i));
        b=a;
    }
    n--;
    set<int> s1;
    s1.insert(-1),s1.insert(n);
    for(i=0;i<n;i++){
        a=q1.top().first,b=q1.top().second;q1.pop();
        v1.push_back(a);
        v2.push_back(b);
        auto itr=s1.lower_bound(b);
        vr.push_back(*itr);
        itr--;
        vl.push_back(*itr);
        s1.insert(b);
    }
    for(i=0;i<m;i++){
        cin>>a>>b;
        a-=2,b--;
        LL s=0;
        for(j=0;j<n;j++){
            c=max(vl[j],a),d=min(vr[j],b);
            if(c>=v2[j] || v2[j]>=d)continue;
            s+=v1[j]*(v2[j]-c)*(d-v2[j]);
        }
        cout<<s<<endl;
    }
}
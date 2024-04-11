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

bool used[300005],usedn[300005];
vector<LL> num(300005,1000000);
vector<LL> path[300005];
vector<LL> his;
LL sum[300005];
LL s[300005];
vector<tuple<LL,LL,LL> > v1;
void dfs(LL p,LL pp){
    LL i,j;
    LL a,b,c;
    if(used[p]){
		if(!usedn[p])return;
        a=1e6,b=0;
        for(i=his.size()-1;i>=0;i--){
            a=min(a,his[i]),b=max(b,his[i]);
            if(his[i]==p)break;
        }
        num[a]=b;
        return;
    }
    used[p]=true,usedn[p]=true;
    his.push_back(p);
    for(auto to:path[p]){
        if(to==pp)continue;
        dfs(to,p);
    }
    his.pop_back();
	usedn[p]=false;
}

int main(){
    LL n,m;
    LL i,j,k;
    LL a,b,c,d;
    cin>>n>>m;
    for(i=0;i<m;i++){
        cin>>a>>b;
        a--,b--;
        path[a].push_back(b);
        path[b].push_back(a);
    }
    for(i=0;i<n;i++){
        if(used[i])continue;
        dfs(i,-1);
    }
    for(i=n-1;i>=0;i--){
        num[i]=min(num[i],num[i+1]);
    }
	//array_show(num,n);
    for(i=0;i<n;i++){
        sum[i+1]=sum[i]+num[i];
    }
    cin>>m;
    LL p,q;
	for(i=0;i<m;i++){
		cin>>a>>b;
		v1.push_back(make_tuple(b,a,i));
	}
	sort(v1.begin(),v1.end());
	p=0;
    for(i=0;i<m;i++){
		tie(b,a,d)=v1[i];
        c=(a+b-2)*(b-a+1)/2;
        c=-c;
        a--;
        for(;p<n && num[p]<b;p++);
        if(p<=a)c+=b*(b-a);
        else if(b<=p)c+=sum[b]-sum[a];
        else{
            c+=sum[p]-sum[a];
            c+=(b-p)*b;
        }
		s[d]=c;
    }
	array_show(s,m,'\n');
}
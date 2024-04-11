#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,s;
pair<int,int>p[2005];
struct line{
    int a,b;double k;
};
int ord[2005],pos[2005];
bool cmp(line x,line y){return x.k<y.k;}
int calc(int a,int b,int c){
	pair<int,int>p1,p2;
	p1=make_pair(p[a].first-p[b].first,p[a].second-p[b].second); 
	p2=make_pair(p[c].first-p[b].first,p[c].second-p[b].second); 
	return abs(p1.first*p2.second-p2.first*p1.second);
}
signed main(){
    cin>>n>>s;s*=2;
    for(int i=1;i<=n;i++)cin>>p[i].first>>p[i].second;
    sort(p+1,p+n+1);
    for(int i=1;i<=n;i++)ord[i]=pos[i]=i;
    vector<line>all;
    for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++){
        double kk;
        if(p[i].first==p[j].first)kk=1e18;
        else kk=1.0*(p[j].second-p[i].second)/(p[j].first-p[i].first);
        all.push_back((line){i,j,kk});
    }
    sort(all.begin(),all.end(),cmp);
    int ans=1e18;
    for(int i=0;i<all.size();i++){
        line L=all[i];
        int x=pos[L.a],y=pos[L.b];
        if(x>y)swap(x,y);
        assert(x+1==y);
        int l=y+1,r=n+1;
        while(r-l>1){
        	int mid=(l+r)/2;
        	if(calc(ord[x],ord[y],ord[mid])<=s)l=mid;
        	else r=mid;
		}
		if(calc(ord[x],ord[y],ord[l])==s){
			cout<<"Yes"<<endl;
			cout<<p[ord[x]].first<<" "<<p[ord[x]].second<<endl;
			cout<<p[ord[y]].first<<" "<<p[ord[y]].second<<endl;
			cout<<p[ord[l]].first<<" "<<p[ord[l]].second<<endl;
			return 0;
		}
		l=0,r=x-1;
		while(r-l>1){
			int mid=(l+r)/2;
			if(calc(ord[mid],ord[x],ord[y])<=s)r=mid;
			else l=mid;
		}
		l++;
		if(calc(ord[x],ord[y],ord[l])==s){
			cout<<"Yes"<<endl;
			cout<<p[ord[x]].first<<" "<<p[ord[x]].second<<endl;
			cout<<p[ord[y]].first<<" "<<p[ord[y]].second<<endl;
			cout<<p[ord[l]].first<<" "<<p[ord[l]].second<<endl;
			return 0;
		}
//        if(x>1)ans=min(ans,calc(ord[x-1],ord[x],ord[y]));
//        if(y<n)ans=min(ans,calc(ord[x],ord[y],ord[y+1]));
        swap(pos[L.a],pos[L.b]);
        swap(ord[x],ord[y]);
    }
    cout<<"No"<<endl;
    return 0;
}
#include<cstdio>
#include<algorithm>
#include<set>
#include<vector>
using namespace std;
const int MAXN=3e5+5,MAXK=1e6+5;
typedef long long ll;
#define mkp make_pair
typedef pair<int,int> pr;
int n,k,a[MAXN],s[MAXN],cnt[MAXK];
pr b[MAXN];
set<int> st;
ll ans;
vector<pr> vec[MAXN];
int main(){
	//freopen("in","r",stdin);
	scanf("%d%d",&n,&k);
	for(int i=1; i<=n; i++)
		scanf("%d",a+i),b[i]=mkp(a[i],i),a[i]%=k,s[i]=(s[i-1]+a[i])%k;
	sort(b+1,b+n+1);
	st.insert(0);
	st.insert(n+1);
	for(int i=n; i; i--){
		int mid=b[i].second;
		auto it=st.lower_bound(mid);
		int r=*it-1;
		it--;
		int l=*it+1;
		//printf("%d %d %d\n",l,mid,r);
		if(mid-l<r-mid){
			for(int j=l; j<=mid; j++){
				int t=(s[j-1]+a[mid])%k;
				// [mid,r]
				vec[mid-1].push_back(mkp(-1,t));
				vec[r].push_back(mkp(1,t));
			}
		}else{
			for(int j=mid; j<=r; j++){
				int t=(s[j]-a[mid]+k)%k;
				// [l-1,mid-1]
				if(l>1) vec[l-2].push_back(mkp(-1,t));
				vec[mid-1].push_back(mkp(1,t));
			}
		}
		st.insert(mid);
	}
	for(int i=0; i<=n; i++){
		cnt[s[i]]++;
		for(int j=0; j<vec[i].size(); j++)
			ans+=vec[i][j].first*cnt[vec[i][j].second];
	}
	printf("%lld\n",ans-n);
	return 0;
}
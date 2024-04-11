#include<bits/stdc++.h>
#define int long long
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
const int inf=0x3f3f3f3f;
const double eps=1e-6;
const int mod=1000000007;
typedef long long ll;
multiset<pair<int,int> >nums;
vector<pair<int,int> >Final;//<pos,val>
int n;
int a[150005];
signed main(){
	scanf("%I64d",&n);
	for(int i=0;i<n;i++)scanf("%I64d",&a[i]),nums.insert(make_pair(a[i],i));
	while(nums.size()){
		multiset<pair<int,int> >::iterator itr=nums.begin();
		multiset<pair<int,int> >::iterator nxt=itr;nxt++;
		if((itr->first)!=(nxt->first)){
			Final.push_back(make_pair(itr->second,itr->first));
			nums.erase(itr);
		}else{
			nums.insert(make_pair((itr->first)+(nxt->first),nxt->second));
			nums.erase(itr);
			nums.erase(nxt);
		}
	}
	sort(Final.begin(),Final.end());
	printf("%I64d\n",Final.size());
	for(int i=0;i<Final.size();i++)printf("%I64d%c",Final[i].second,i==Final.size()-1?'\n':' ');
	return 0;
}
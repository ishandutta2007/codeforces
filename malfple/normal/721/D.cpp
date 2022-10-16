#include <iostream>
#include <cstdio>

#include <algorithm>
#include <cstring>

#include <vector>
#include <string>
#include <queue>
#include <utility>

#define repp(i,a,b,d) for(int i=a; i<=b; i+=d)
#define rep(i,a,b) repp(i,a,b,1)

#define ff first
#define ss second
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;

ll arr[200005];
priority_queue<pair<ll,int> >pq;

int main(){
	int n,k,x;
	scanf("%d %d %d",&n,&k,&x);
	int phase = 0;
	rep(i,1,n){
		scanf("%lld",&arr[i]);
		if(arr[i] < 0)phase ^= 1;
		pq.push(mp(-abs(arr[i]), i));
	}
	
	rep(i,1,k){
		int id = pq.top().ss;
		pq.pop();
		
		if(phase){
			if(arr[id] >= 0)arr[id] += x;
			else arr[id] -= x;
		}else{
			if(arr[id] >= 0){
				arr[id] -= x;
				if(arr[id] < 0)phase = 1;
			}else{
				arr[id] += x;
				if(arr[id] >= 0)phase = 1;
			}
		}
		pq.push(mp(-abs(arr[id]), id));
	}
	
	rep(i,1,n)printf("%lld ",arr[i]);
	printf("\n");
	return 0;
}
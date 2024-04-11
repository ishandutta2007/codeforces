#include <bits/stdc++.h>
using namespace std;
#define modulo 998244353
#define mod(mod_x) ((((long long)mod_x)+modulo)%modulo)
#define Inf 1000000000000


int main() {
	
	int w,l;
	scanf("%d %d",&w,&l);
	
	vector<int> a(w);
	for(int i=0;i<w-1;i++)scanf("%d",&a[i]);
	a[w-1] = 1000000001;
	vector<int> cnt(w,0);
	
	for(int i=0;i<l;i++){
		cnt[i] = a[i];
	}
	
	int now = l-1;
	
	while(true){
		for(int i=0;i<l;i++){
			int from = now-i;
			int to = min(w-1,l+now-i);
			
			if(a[to]<cnt[from]){
				cnt[to] += a[to];
				cnt[from] -= a[to];
				a[to] = 0;
				if(from!=0){
					cnt[from-1] += cnt[from];
					cnt[from] = 0;
				}
			}
			else{
				cnt[to] += cnt[from];
				a[to] -= cnt[from];
				cnt[from] = 0;
			}
			
		}
		
		now = min(now+l,w-1);
		int R = now;
		int L = now-l+1;
		while(true){
			while(L<R&&R!=0&&a[R]==0)R--;
			while(L<R&&L!=w-1&&cnt[L]==0)L++;
			if(L>=R)break;
			//cout<<l<<','<<r<<endl;
			int x = min(cnt[L],a[R]);
			if(x==0)break;
			cnt[L]-=x;
			cnt[R]+=x;
			a[R]-=x;
		}
		
		//for(int i=0;i<w;i++)cout<<cnt[i]<<',';
		//cout<<endl;
		
		if(now==w-1)break;
	}
	
	cout<<cnt.back()<<endl;
	
	
	
	
	
    return 0;
}
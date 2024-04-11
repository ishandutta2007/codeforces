#include<bits/stdc++.h>
using namespace std;
int n;
long long int a[111111],s[111111];
int pos[111111];
int A[111111],LA;
int cnt1[111111],cnt2[111111];
bool chk(int*cnt,int x){
	int it = lower_bound(A,A+LA,x)-A;
	if(it < LA && A[it] == x)
		return cnt[it] > 0;
	return false;
}
int main(){
	scanf("%d",&n);
	for(int i=1; i<=n; i++){
		int x;
		scanf("%d",&x);
		a[i] = x;
		s[i] = s[i-1] + x;
		A[LA ++] = x;
	}
	sort(A, A+LA);
	LA = unique(A, A+LA) - A;
	for(int i=1; i<=n; i++){
		pos[i] = lower_bound(A,A+LA,(int)a[i])-A;
		cnt2[pos[i]] ++;
	}

	for(int i=0; i<=n; i++){
		long long int A = s[i], B = s[n] - s[i];
		if(A == B){
			puts("YES");
			return 0;
		}
		if(A > B && (A-B)%2==0){
			long long int w = (A-B)/2;
			if(w <= 1000000000 && chk(cnt1, (int)w)){
				puts("YES");
				return 0;
			}
		}else
		if(A < B && (B-A)%2==0){
			long long int w = (B-A)/2;
			if(w <= 1000000000 && chk(cnt2, (int)w)){
				puts("YES");
				return 0;
			}
		}
		if(i == n)break;
		cnt1[pos[i+1]]++;
		cnt2[pos[i+1]]--;
	}
	puts("NO");
	return 0;
}
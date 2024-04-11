#include <bits/stdc++.h>
#define pb push_back
#define F first
#define S second
using namespace std;

typedef long long ll;

const int P = 20;
int sieve[P+5];

int t;
ll k;
int cnt[P];

int nom[P]; // all
int nom_zeroback[P];
int denom[P];

void factorize(int* arr, int sz){
	for(int i=2; i<=sz; i++){
		if(sieve[i] == i)continue;
		int c = i;
		while(c > 1){
			int p = sieve[c];
			int cc = 0;
			while(sieve[c] == p){
				c /= p;
				cc++;
			}
			arr[p] += arr[i] * cc;
		}
		arr[i] = 0;
	}
}

void print(int* arr, int sz){
	printf("ARR\n");
	for(int i=2; i<=sz; i++){
		if(arr[i] == 0)continue;
		printf("%d ^ %d\n",i,arr[i]);
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	sieve[1] = 1;
	for(int i=2; i<=P; i++){
		if(sieve[i] == 0){
			for(int j=i; j<=P; j+=i){
				sieve[j] = i;
			}
		}
	}
	
	cin>>t;
	while(t--){
		cin>>k;
		
		memset(cnt, 0, sizeof cnt);
		int sz = 0;
		for(int i=2; k; i++, sz++){
//			printf("in %d\n",k % i);
			cnt[k % i]++;
			k /= i;
		}
		
		memset(nom, 0, sizeof nom);
		memset(nom_zeroback, 0, sizeof nom_zeroback);
		memset(denom, 0, sizeof denom);
		
		// numerator
		// all
		int curr = cnt[0];
		for(int i=1; i<=sz; i++){
			curr += cnt[i];
			nom[curr]++;
			curr--;
		}
		// zero back
		if(cnt[0] > 0){
			nom_zeroback[cnt[0]]++;
			int curr = cnt[0]-1;
			for(int i=1; i<sz; i++){
				curr += cnt[i];
				nom_zeroback[curr]++;
				curr--;
			}
		}
		
		//denominator
		for(int i=0; i<=sz; i++){
			if(cnt[i] > 1){
				denom[cnt[i]]++;
			}
		}
		for(int i=sz; i>1; i--){
			denom[i-1] += denom[i];
		}
		
//		print(nom, sz);
//		print(nom_zeroback, sz);
//		print(denom,sz);
		
		// prime factorization
		factorize(nom, sz);
		factorize(nom_zeroback, sz);
		factorize(denom, sz);
		
		ll ans = 1;
//		printf("ans\n");
		for(int i=2; i<=sz; i++){
//			printf("%d ^ %d\n",i,nom[i]-denom[i]);
			for(int j=1; j<=nom[i]-denom[i]; j++){
				ans *= i;
			}
		}
		if(cnt[0] > 0 && nom_zeroback[0] == 0){
			ll zeroback = 1;
//			printf("zeroback\n");
			for(int i=2; i<=sz; i++){
//			printf("%d ^ %d\n",i,nom_zeroback[i]-denom[i]);
				for(int j=1; j<=nom_zeroback[i]-denom[i]; j++){
					zeroback *= i;
				}
			}
			ans -= zeroback;
		}
		
		cout << ans-1 << endl;
	}
	
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int s[7];
int ans = 0;
void r(int i, int j){
	int z = min(s[i],s[j]);
	s[i] -= z;
	s[j] -= z;
}
void m(int c){
	for(int i = c; i >= 0; i--){
		if(s[i] > 0){
			s[i]--;
			return;
		}
	}
}
int main(){
	int n;
	cin >> n;
	int a, b, c;
	cin >> a >> b >> c;
	if(a > b) swap(a,b);
	if(b>c) swap(c,b);
	if(a > b) swap(a,b);
	if(a > b) swap(a,b);
	if(b>c) swap(c,b);
	if(a > b) swap(a,b);
	for(int i = 0; i < 7; i++) s[i] = 0;
	if(c <= a+b){
		for(int i = 0; i < n; i++){
			int r;
			cin >> r;
			if(r <= a){
				s[0]++;
			} else if(r <= b){
				s[1]++;
			} else if(r <= c){
				s[2]++;
			} else if(r <= a+b){
				s[3]++;
			} else if(r <= a+c){
				s[4]++;
			} else if(r <= b+c){
				s[5]++;
			} else if(r <= a+b+c){
				s[6]++;
			} else {
				cout << -1 << endl;
				return 0;
			}
		}

		while(s[6] > 0){
			m(6); ans++;
		}
		while(s[5] > 0){
			m(5); m(0); ans++;
		}
		while(s[4] > 0){
			m(4); m(1); ans++;
		}
		while(s[3] > 0){	
			m(3); m(2); ans++;
		}

		while(1){
			if(s[2] + 1 >= (max(s[1],(s[1]+s[0]+1)/2)+s[3]) && (max(s[1],(s[1]+s[0]+1)/2)+s[3] + 1 >= s[2]) ){
				ans += max(s[2], (max(s[1],(s[1]+s[0]+1)/2)+s[3]) );
				break;
			} else if(s[2] + 1 < (max(s[1],(s[1]+s[0]+1)/2)+s[3]) ){
				if(s[1] > 0){
					s[1]--;
					s[2]++;
				} else {
					s[0]--;
					s[2]++;
				}
			} else {
				s[2]--;
				s[3]++;
			}

		}


		cout << ans << endl;
	} else {
		for(int i = 0; i < n; i++){
			int r;
			cin >> r;
			if(r <= a){
				s[0]++;
			} else if(r <= b){
				s[1]++;
			} else if(r <= a+b){
				s[2]++;
			} else if(r <= c){
				s[3]++;
			} else if(r <= a+c){
				s[4]++;
			} else if(r <= b+c){
				s[5]++;
			} else if(r <= a+b+c){
				s[6]++;
			} else {
				cout << -1 << endl;
				return 0;
			}
		}

		while(s[6] > 0){
			m(6); ans++;
		}
		while(s[5] > 0){
			m(5); m(0); ans++;
		}
		while(s[4] > 0){
			m(4); m(1); ans++;
		}
		while(1){
			if(s[3] >= s[2] + max((s[1]+s[0]+1)/2, s[1])){
				ans += s[3];
				break;
			} else if(s[2] > 0){
				s[2]--;
				s[3]++;
			} else if(s[1] > 0){
				s[1]--;
				s[3]++;
			} else {
				s[0]--;
				s[1]++;
			}
		}
		cout << ans << endl;
	}

}
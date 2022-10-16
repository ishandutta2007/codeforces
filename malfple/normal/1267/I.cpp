#include <bits/stdc++.h>
#define pb push_back
#define F first
#define S second
using namespace std;

typedef long long ll;

int t;
int n;
vector<pair<int,int> >vec; // pair of master and servant

bool ask_lt(int a, int b){
	cout << "? " << a << " " << b << endl;
	char c;
	cin>>c;
	return c == '<';
}

int main(){
//	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin>>t;
	while(t--){
		cin>>n;
		vec.clear();
		for(int i=1; i<=n; i++){ // initial pairing
			if(ask_lt(i, n+i)){
				vec.pb({n+i, i});
			}else{
				vec.pb({i, n+i});
			}
		}
		for(int left = 2 * n; left > n; left--){
			// finding worst
			sort(vec.begin(), vec.end());
			int worst = -1;
			for(int i=((vec[0].F == -1)?1:0); i<vec.size(); i++){
				if(worst == -1){
					worst = vec[i].S;
				}else if(ask_lt(vec[i].S, worst)){
					worst = vec[i].S;
				}
			}
			if(vec[0].F == -1){
				if(ask_lt(vec[0].S, worst)){
					worst = vec[0].S;
				}
			}
			
//			printf("disqualify %d\n",worst);
			// "worst" is now disqualified
			for(int i=0; i<vec.size(); i++){
				if(vec[i].S == worst){
					vec[i].S = vec[i].F;
					vec[i].F = -1;
					break;
				}
			}
			if(left == n+1){ // no need to check anymore
				break;
			}
			sort(vec.begin(), vec.end());
			if(vec[0].S == -1){ // "worst" was alone, having no masters
//				printf("pop empty\n");
				reverse(vec.begin(), vec.end());
				vec.pop_back();
			}else if(vec.size() > 1 && vec[1].F == -1){ // 2 people with no masters
//				printf("pair up %d %d\n",vec[0].S,vec[1].S);
				vec[1].F = vec[0].S; // pair up
				if(ask_lt(vec[1].F, vec[1].S)){
					swap(vec[1].F, vec[1].S);
				}
				reverse(vec.begin(), vec.end());
				vec.pop_back();
			}
		}
		cout << "!" << endl;
	}
	
	return 0;
}
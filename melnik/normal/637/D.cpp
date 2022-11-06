#include <bits/stdc++.h>

using namespace std;

int main(){
//	freopen("input.txt","r",stdin);	

	int n,m,s,d;
	cin >> n >> m >> s >> d;

	vector<int> kit(n+2,-1);
	kit[n+1] = m+1;

	for(int i = 0; i<n; i++){
		cin >> kit[i];
	}
	sort(kit.begin() , kit.end() );
//	for(int i = 0; i<=n+1; i++){
//		cout << kit[i] << " ";
//	}
//	cout << endl;
	
	vector< pair< int , int > > dp(n+2, make_pair(0 , -1) );
	dp[0].first = 1;


	for(int i = 0; i<=n; i++){
		if(dp[i].first == 1){
			if(kit[i+1] - kit[i] - 2 >= s){
				int next_place = kit[i+1]-1 + d;

				int l = 0, r = n+2, m;
				while(r - l > 1){
					m = (l + r)/2;

					if(kit[m] >= next_place)
						r = m;
					else
						l = m;
				}
				int cur = l;

				for(int j = cur; j >= i; j--){
					if(dp[j].first == 1)
						break;
					else{
						dp[j].first = 1;
						dp[j].second = i;
					}
				}
			}
		}
	}
//	cout << "All is ready" << endl;
	

	stack< pair<int,int> > help;

	int cur = n;
	if(dp[cur].first == 0){
		cout << "IMPOSSIBLE" << endl;
		return 0;
	}

	while(dp[cur].second != -1){
		if(kit[cur+1] - kit[cur] - 2 != 0)
			help.push( make_pair(1,kit[cur+1] - kit[cur] - 2) );

		int prev = dp[cur].second;
		help.push( make_pair(2,kit[cur] - kit[prev+1] + 2) );
		cur = prev;
	}
	help.push( make_pair(1,kit[1] - kit[0] - 2) );

	while( !help.empty() ){
		pair<int,int> temp = help.top();
		help.pop();
		if(temp.first == 1)
			cout << "RUN " << temp.second << endl;
		else
			cout << "JUMP " << temp.second << endl;
	}


	return 0;
}
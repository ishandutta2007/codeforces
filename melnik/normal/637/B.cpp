#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
    int n;
    cin >> n;

    vector<string> q(n);

    for(int i = 0; i<n; i++){
    	string name;
    	cin >> name;
    	q[i] = name;
    }

    set<string> help;
    queue<string> sol;

    for(int i = n-1; i>=0; i--){
    	string name = q[i];
    	if( !help.count(name) ){
    		help.insert(name);
    		sol.push(name);
    	}
    }


    while( !sol.empty() ){
    	cout << sol.front() << endl;
    	sol.pop();
    }
	

	return 0;
}
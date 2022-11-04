/*
 * in the name of god
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int n;
int poi[100];
string M;
string b[100];
vector <int> Q[100];

inline void setQ (int id, string s){
	
	int l= (int)s.size();

	for (int i=0, leni=(int)M.size()-l; i<=leni ; i++){

		bool flag= true;

		for (int j=0;j<l;j++) if (s[j]!=M[i+j]){
			flag= false;
			break;
		}

		if (flag==true)
			Q[id].push_back (i);
	}
}
/*************************************/
int main(){
	getline (cin, M);

	cin >> n;
	getline (cin,b[0]);

	for (int i=1;i<=n;i++){
		getline (cin, b[i]);
		setQ(i,b[i]);
	}

	int res=0, pos=0;
	
	for (int i=0;i<(int)M.size();i++){

		int beg=-1;

		for (int j=1;j<=n;j++) if (Q[j].size()){

			int maxl= i-(int)b[j].size()+1;

			while (poi[j]<(int)Q[j].size() && Q[j][poi[j]]<=maxl){
				
				beg= max (beg, Q[j][poi[j]]);
				poi[j]++;
			
			}

			if (poi[j]>0)
				poi[j]--;
		}

		beg++;

		if (res < i-beg+1){
			res= i-beg+1;
			pos= beg;
		}
	}

	cout << res << ' ' << pos << endl;

	return 0;
}
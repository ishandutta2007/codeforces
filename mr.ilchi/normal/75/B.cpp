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
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>
#include <map>

using namespace std;

int n;
string me, s;
map <string, int> score;

int main(){
	cin >> me >> n;

	for (int i=1;i<=n;i++){
		string X; cin >> X;
		string tmp; cin >> tmp;

		if (tmp=="posted"){
			cin >> tmp;
			string Y; cin >> Y;
			Y= Y.substr (0, Y.size()-2);
			cin >> tmp;

			if (X!=me && Y!=me){
				if (score.find(X)== score.end())
					score[X]=0;
				if (score.find(Y)== score.end())
					score[Y]=0;
			}

			else{
				score[X]+= 15; score[Y]+=15;
			}
		}

		else if (tmp=="commented"){
			cin >> tmp;
			string Y; cin >> Y;
			Y= Y.substr (0,Y.size()-2);
			cin >> tmp;

			if (X!=me && Y!=me){
				if (score.find(X)== score.end())
					score[X]=0;
				if (score.find(Y)== score.end())
					score[Y]=0;
				
			}
			else{
				score[X]+= 10; score[Y]+= 10;
			}
		}

		else{
			string Y; cin >> Y;
			Y= Y.substr (0, Y.size()-2);
			cin >> tmp;

			if (X!=me && Y!=me){
				if (score.find(X)== score.end())
					score[X]=0;
				if (score.find(Y)== score.end())
					score[Y]=0;
			}

			else{
				score[X]+= 5; score[Y]+= 5;
			}
		}
	}


	vector < pair <int, string> > Q;

	for (map <string, int> :: iterator it= score.begin(); it!=score.end(); it++) if ((it->first)!=me)
		Q.push_back (make_pair (-(it->second), it->first));

	sort (Q.begin(), Q.end());

	for (int i=0;i<(int)Q.size();i++)
		cout << Q[i].second << endl;

	return 0;
}
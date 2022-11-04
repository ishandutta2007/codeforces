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
 */

#include <iostream>

using namespace std;

const int maxK= 26+5;

bool mark[maxK];
int k;
string s;

int main(){
	cin >> k >> s;
	int n= (s.size()), mid= (s.size()/2);
	if (n%2==0)
		mid --;
	for (int i=0;i<= mid;i ++){
		int oth= n-i-1;
		if (s[i]!='?'){
			if (s[oth]=='?')
				s[oth]= s[i];
			else if (s[i]!= s[oth]){
				cout << "IMPOSSIBLE" << endl;
				return 0;
			}
			mark[s[i]-'a'+1]= true;
		}
		else if (s[oth]!='?'){
			s[i]= s[oth];
			mark[s[i]-'a'+1]= true;
		}
	}
	int p=mid;
	for (int i= k;i>= 1;i --){
		if (!mark[i]){
			char tmp= i+'a'-1;
			while (p>=0 && s[p]!='?')
				p--;
			if (p < 0){
				cout << "IMPOSSIBLE" << endl;
				return 0;
			}
			s[p]= s[n-p-1]= tmp;
		}
	}
	for (int i=0;i< (int)s.size();i ++)
		if (s[i]=='?')
			s[i]= 'a';

	cout << s << endl;
	return 0;
}
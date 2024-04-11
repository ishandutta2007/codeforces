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
 *
 */

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
#include <cstdlib>

using namespace std;

vector <char> M;

int main(){
	char past=0;
	char ch;
	while (scanf ("%c", &ch)!=EOF){
		if (M.size()==0 && ch==' ')
			continue;

		if (ch!=' ' || past!=' '){
			if (ch!='\n'){
				M.push_back (ch);
				past= ch;
			}
		}
	}

	if (M.size()==0){
		cout << endl;
		return 0;
	}

	string ans= "";

	for (int i=0;i<(int)M.size();i++){
		char back= '?';

		if (ans.size())
			back= ans[ans.size()-1];

		if (M[i]>='0' && M[i]<='9'){
			if (ans.size() && (i!=0 && !(M[i-1]>='0' && M[i-1]<='9')) && back>='0' && back<='9')
				ans+= ' ';
			ans+= M[i];
		}
		else if (M[i]==','){
			ans+= ',';
			if (i!=(int)M.size()-1)
				ans+= ' ';
		}

		else if (M[i]=='.'){
			if (ans.size()>0 && back!=' ')
				ans+=' ';

			i+= 2;
			ans+= "...";
		}
	}
	cout << ans << endl;

	return 0;
}
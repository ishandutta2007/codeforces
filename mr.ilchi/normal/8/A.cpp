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
#include <string>
#include <algorithm>
#include <cstdio>

using namespace std;

string M;
string A, B;

int main (){
	bool ab= false, ba= false;
	cin >> M >> A >> B;
	if (M.find(A)!= M.npos){
		int start= M.find(A)+A.size();
		if ((M.substr(start,M.size()-start).find(B))!= M.npos)
			ab=true;
	}
	reverse (M.begin(), M.end());
	if (M.find(A)!= M.npos){
		int start= M.find(A)+A.size();
		if ((M.substr(start,M.size()-start).find(B))!= M.npos)
			ba=true;
	}
	(ab  && ba) ? puts ("both") :
	(!ab &&!ba) ? puts ("fantasy") :
	(ab) ? puts ("forward") : puts ("backward");
	
	return 0;
}
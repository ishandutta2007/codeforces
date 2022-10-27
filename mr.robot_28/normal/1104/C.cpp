#include<bits/stdc++.h> 

using namespace std; 
int main () { 
	long long al = 0, ar = 1; 
	string s; 
	cin >> s; 
	for (long long i = 0; i < s.length(); i++) { 
		if (s[i] == '0') 
		{ 
			cout << 2 * al + 1 << " " << 1 << endl; 
			al = (al + 1) % 2; 
		} 
		else if (s[i] == '1') 
		{ 
			cout << ar << " " << 2 << endl; 
			ar++;
			if (ar == 5) 
			{
				ar = 1;
			} 
		} 
	} 
}
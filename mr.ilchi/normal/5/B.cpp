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
#include <string>
#include <cstdio>

using namespace std;

const int MAXN= 1000+5;

int n;
string s[MAXN];

int main (){
	int maxL= 0;
	while (getline (cin, s[n]))
		maxL= max (maxL, (int)s[n++].size());
	for (int i= -1;i<= maxL;i ++)
		putchar ('*');
	putchar ('\n');
	int l= 0, r= 1;
	for (int i= 0;i< n;i ++){
		putchar ('*');
		int diff= maxL- s[i].size();
		for (int j= (diff+l)/2;j> 0;j --)
			putchar (' ');
		cout << s[i];
		for (int j= (diff+r)/2;j> 0;j --)
			putchar (' ');
		putchar ('*');
		putchar ('\n');
		if (diff & 1)
			swap (l, r);
	}
	for (int i= -1;i<= maxL;i ++)
		putchar ('*');
	putchar ('\n');

	return 0;
}
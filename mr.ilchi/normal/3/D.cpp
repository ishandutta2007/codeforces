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
#include <queue>

#define Pair pair <int,int> 

using namespace std;

typedef long long ll;

const int MAXN= 4000*100+5;

char s[MAXN];

int main (){
	gets (s);
	int hei= 0;
	ll res= 0;
	priority_queue <Pair> Q;
	for (int i= 0;s[i];i ++){
		if (s[i]== '(')
			hei ++;
		else if (s[i]== ')')
			hei --;
		else{
			int open, close;
			scanf ("%d%d", &open, &close);
			s[i]= ')';
			hei --;
			res+= (ll)close;
			Q.push (Pair(close-open,i));
		}
		if (hei < 0){
			if (Q.empty ()){
				puts ("-1");
				return 0;
			}
			Pair mini= Q.top ();
			Q.pop ();
			res-= (ll)mini.first;
			s[mini.second]= '(';
			hei+= 2;
		}
	}
	if (hei== 0){
		printf ("%I64d\n", res);
		puts (s);
	}
	else
		puts ("-1");

	return 0;
}
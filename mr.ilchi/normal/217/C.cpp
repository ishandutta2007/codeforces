/*
 * in the name of god
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
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <queue>
#include <complex>
#include <stack>
#include <deque>
#include <queue>
#include <iomanip>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef complex<double> point;
typedef long double ldb;

int n,len;
int match[5000000];
string s,ss;

struct node{
	bool m00,m01,m11;
	node () {}
	node (bool m00, bool m01, bool m11) : m00(m00), m01(m01), m11(m11) {}
	void print(){
		cout << "node : " << m00 << ' ' << m01 << ' ' << m11 << endl;
	}
};

node go (int pos){
	if (s[pos]=='?')
		return node(0,1,0);
	if (s[pos]=='1')
		return node(0,0,1);
	if (s[pos]=='0')
		return node(1,0,0);
	if (match[pos] == pos+2)
		return go(pos+1);
	int lef = pos+1;
	int rig = match[pos+1]+2;
	node f1 = go(lef);
	node f2 = go(rig);
	char op = s[match[pos+1]+1];
	if (op=='&'){
		node ret = node(0,0,0);
		ret.m00 = (f1.m00 || f2.m00 || (f1.m01 && f2.m01));
		ret.m11 = (f1.m11 && f2.m11);
		ret.m01 = ((f1.m01 && (f2.m01 || f2.m11)) || ((f1.m11 || f1.m01) && f2.m01)); 
		return ret;
	}
	if (op=='|'){
		node ret = node(0,0,0);
		ret.m00 = (f1.m00 && f2.m00);
		ret.m11 = (f1.m11 || f2.m11 || (f1.m01 && f2.m01));
		ret.m01 = ((f1.m01 && (f2.m00 || f2.m01)) || (f2.m01 && (f1.m00 || f1.m01)));
		return ret;
	}
	if (op=='^'){
		node ret = node(0,0,0);
		ret.m00 = ((f1.m00 && f2.m00) || (f1.m11 && f2.m11) || (f1.m01 && f2.m01));
		ret.m11 = ((f1.m00 && f2.m11) || (f1.m11 && f2.m00) || (f1.m01 && f2.m01));
		ret.m01 = ((f1.m01 && (f2.m11 || f2.m00)) || (f2.m01 && (f1.m11 || f1.m00)));
		return ret;
	}
	return node(0,0,0);
}

int main(){
	cin >> n;
	cin >> ss;
	for (int i=0; i<(int)ss.size(); i++){
		if (ss[i]=='0' || ss[i]=='1' || ss[i]=='?'){
			s+= '(';
			s+= ss[i];
			s+= ')';
		}
		else
			s+= ss[i];
	}
	stack <int> st;
	len = (int)s.size();
	for (int i=0; i<len; i++){
		if (s[i]=='(')
			st.push(i);
		if (s[i]==')'){
			match[st.top()] = i;
			st.pop();
		}
	}
	node ans = go(0);
	if (ans.m01)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	return 0;
}
#include <algorithm>
#include <cassert>
#include <iostream>
#include <iterator>
#include <list>

using namespace std;
list <char> s;
list <char> in;
list <int> l;

char itoc(int i) {
	return ((char) (i+48));
}

void add(int i) {
	s.push_back(itoc(i));
}

int main() {
	int n;
	bool b=true;
	char p;
	list<int>::iterator it;
	list<char>::iterator it2, it3;
	cin >> n;
	if(n==0)
		s.push_front('0');
	else {
		while(n>0) {
			l.push_front(n%10);
			n= n/10;
		}
		l.sort();
		it=l.begin();
		while(*it==0)
			++it;
		s.push_back(itoc(*it));
		l.erase(it);
		for_each(l.begin(),l.end(),add);
	}
	while(cin>>p)
		in.push_back(p);
	b =in.size()==s.size();
	if(b) {
		it2 = s.begin();
		it3 = in.begin();
		while(b && it2!=s.end()) {
			b= *it2 == *it3;
			++it2;
			++it3;
		}
	}
	
	cout << (b?"OK":"WRONG_ANSWER") << endl;
	return 0;
}
#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
using namespace std;

struct Func{
	string name;
	vector <int> type;
	Func(){
		name = "";
		type.clear();
	}
}f[1010];

struct Value{
	string name;
	int type;
	Value(){
		name = "";
		type = -1;
	}
}v[1010];

bool check(Func a, Func b){
	if(a.name != b.name || a.type.size() != b.type.size()) return 0;
	for(int i = 0; i < (int)a.type.size(); ++i)
		if(a.type[i] != b.type[i] && a.type[i] != 3 && b.type[i] != 3) return 0;
	return 1;
}

string s;

int main(){
	int T,M,K;
	scanf("%d\n", &T);
	for(int t = 1; t <= T; ++t){
		getline(cin, s);
		int i = 0;
		while(s[i] == ' ') ++i;
		i += 4;
		while(s[i] == ' ') ++i;
		while(s[i] != ' ' && s[i] != '(') f[t].name += s[i++];
		while(s[i] != '(') ++i;
		++i;
		while(s[i] != ')'){
			while(s[i] == ' ') ++i;
			switch(s[i]){
				case 'i' :
					f[t].type.push_back(0);
					while(s[i] != ')' && s[i] != ',') ++i;
					break;
				case 'd' :
					f[t].type.push_back(1);
					while(s[i] != ')' && s[i] != ',') ++i;
					break;
				case 's' :
					f[t].type.push_back(2);
					while(s[i] != ')' && s[i] != ',') ++i;
					break;
				case 'T' :
					f[t].type.push_back(3);
					while(s[i] != ')' && s[i] != ',') ++i;
					break;
				default : break;
			}
			if(s[i] == ')') break;
			++i;
		}
	}
	
//	for(int i = 1; i <= T; ++i){
//		cout << f[i].name << ' ';
//		for(vector <int> :: iterator it = f[i].type.begin(); it != f[i].type.end(); ++it)
//			printf("%d ", *it);
//		cout << endl;
//	}
	
	scanf("%d\n", &M);
	for(int m = 1; m <= M; ++m){
		getline(cin, s);
		int i = 0;
		while(s[i] == ' ') ++i;
		switch(s[i]){
			case 'i' :
				v[m].type = 0;
				i += 3;
				break;
			case 'd' :
				v[m].type = 1;
				i += 6;
				break;
			case 's' :
				v[m].type = 2;
				i += 6;
				break;
			case 'T' :
				v[m].type = 3;
				i++;
				break;
		}
		while(s[i] == ' ') ++i;
		while(i < (int)s.size() && s[i] != ' ') v[m].name += s[i++];
	}
	
//	for(int i = 1; i <= M; ++i)
//		cout << v[i].name << ' ' << v[i].type << endl;
	
	scanf("%d\n", &K);
	while(K--){
		int sum = 0, i = 0;
		Func fn;
		getline(cin, s);
		while(s[i] == ' ') ++i;
		while(s[i] != ' ' && s[i] != '(') fn.name += s[i++];
		while(s[i] != '(') ++i;
		++i;
		while(s[i] != ')'){
			while(s[i] == ' ') ++i;
			string vn = "";
			while(s[i] != ' ' && s[i] != ')' && s[i] != ',') vn += s[i++];
			while(s[i] == ' ' || s[i] == ',') ++i;
			for(int m = 1; m <= M; ++m)
				if(v[m].name == vn){
					fn.type.push_back(v[m].type);
					break;
				}
		}
		
//		cout << fn << ' ';
//		for(vector <int> :: iterator it = ft.begin(); it != ft.end(); ++it)
//			cout << *it << ' ';
//		cout << endl;
		
		for(int t = 1; t <= T; ++t)
			if(check(f[t], fn)) sum++;
		printf("%d\n", sum);
	}
	
	return 0;
}
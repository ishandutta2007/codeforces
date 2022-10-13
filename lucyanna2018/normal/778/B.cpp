#include<string>
#include<iostream>
#include<cctype>
#include<map>
using namespace std;
#define ran 5555
int n,m;
bool typ[ran];
string val[ran];
int op1[ran],op2[ran],oper[ran];
map<string,int> Map;
int res1[ran],res2[ran];

int vv[ran];

int main(){
	ios::sync_with_stdio(false);
	cin >> n >> m;
	Map["?"] = 0;
	for(int i=1; i<=n; i++){
		string name;
		cin >> name;
		Map[name] = i;
		string v1;
		cin >> v1;
		cin >> v1;
		if(isdigit(v1[0])){
			typ[i] = true;
			val[i] = v1;
		}else{
			typ[i] = false;
			op1[i] = Map[v1];
			cin >> v1;
			oper[i] = (int)(v1[0]);
			cin >> v1;
			op2[i] = Map[v1];
		}
	}
	for(int i=0; i<m; i++){
		int s0 = 0, s1 = 0;
		for(int x = 0; x < 2; x++){
			vv[0] = x;
			int sum = 0;
			for(int j = 1; j<=n; j++){
				if(typ[j]){
					vv[j] = (val[j][i] == '1' ? 1 : 0);
				}else{
					if(oper[j] == 'X')
						vv[j] = vv[op1[j]] ^ vv[op2[j]];
					else
					if(oper[j] == 'A')
						vv[j] = vv[op1[j]] & vv[op2[j]];
					else
					if(oper[j] == 'O')
						vv[j] = vv[op1[j]] | vv[op2[j]];
				}
				sum += vv[j];
			}
			if(x == 0)s0 = sum;else
				s1 = sum;
		}
		if(s0 == s1){
			res1[i] = res2[i] = false;
		}else
		if(s0 < s1){
			res1[i] = false;
			res2[i] = true;
		}else{
			res1[i] = true;
			res2[i] = false;
		}
	}
	for(int i=0; i<m; i++)
		putchar(res1[i] ? '1' : '0');puts("");
	for(int i=0; i<m; i++)
		putchar(res2[i] ? '1' : '0');puts("");
	return 0;
}
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
 */

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int MAXN= 1000*100+5;

int n, cap, res;
int len[3], val[MAXN];
int v[3][MAXN];
vector <int> q;

inline bool cmp (const int &a1, const int &a2){
	return val[a1] < val[a2];
}
/****************************************/
inline void POP (int type){
	res+= val[v[type][len[type]]];
	q.push_back (v[type][len[type]--]);
	cap-= type;
}
/****************************************/
int main (){
	cin >> n >> cap;
	for (int i= 1;i<= n;i ++){
		int type;
		cin >> type >> val[i];
		v[type][++len[type]]= i;
	}
	
	sort (&v[1][1], &v[1][len[1]+1], cmp);
	sort (&v[2][1], &v[2][len[2]+1], cmp);

	while ((cap > 1) && (len[1] > 1) && len[2]){
		if (val[v[1][len[1]]]+ val[v[1][len[1]-1]]>= val[v[2][len[2]]])
			POP (1);
		else
			POP (2);
	}
	if (cap > 1){
		if (len[1] > 1){
			while (cap && len[1])
				POP (1);
		}
		else{
			while ((cap > 1) && len[2])
				POP (2);
			if (cap)
				POP (1);
			else if (val[v[1][len[1]]] > val[v[2][len[2]+1]]){
				q.pop_back ();
				POP (1);
			}
		}		
	}
	
	else if (cap== 1 && len[1])
		POP (1);

	cout << res << endl;
	for (int i= 0;i< (int)q.size ();i ++)
		cout << q[i] << ' ';
	cout << endl;

	return 0;
}
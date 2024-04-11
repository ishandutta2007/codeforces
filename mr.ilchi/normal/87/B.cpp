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
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <map>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int n;
string s,A,B;
map <string, int> mip;

inline void print (int x){

	if (x<0) {
		puts ("errtype");
		return;
	}
	
	cout << "void";
	for (int i=1;i<=x;i++)
		cout << "*";
	cout << endl;
}
/*************************/
int main(){

	cin >> n; 

	mip["void"]= 0;

	for (int i=1;i<=n;i++){
	
		cin >> s;

		if (s=="typeof"){
			
			cin >> A;

			int pand=0 , pstar=(int)A.size()-1;

			while (A[pand]=='&') pand++;

			while (A[pstar]=='*') pstar--;

			string tmp= A.substr (pand, pstar+1-pand);

			if (mip.find(tmp)==mip.end() || (mip[tmp]==-1)) puts ("errtype");

			else print (mip[tmp]-pand+((int)A.size()-pstar-1));
		}

		if (s=="typedef"){

			cin >> A >> B;

			if (A.find("errtype")==A.npos){
					
				int pand=0 , pstar=(int)A.size()-1;

				while (A[pand]=='&') pand++;

				while (A[pstar]=='*') pstar--;

				string tmp= A.substr (pand , pstar+1-pand);

				if (mip.find(tmp)!=mip.end() && mip[tmp]!=-1){
					
					int tt= mip[tmp] - pand + ((int)A.size()-pstar-1);

					if (tt >= 0)
						mip[B]= tt;

					else
						mip[B]= -1;
				}

				else
					mip[B]= -1;
			}

			else
				mip[B]= -1;
		}
	}

	return 0;
}
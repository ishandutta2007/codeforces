#include <bits/stdc++.h>
using namespace std;
char sto[10][100]={ ("+------------------------+"), ("|#.#.#.#.#.#.#.#.#.#.#.|D|)"), ("|#.#.#.#.#.#.#.#.#.#.#.|.|"), ("|#.......................|"), ("|#.#.#.#.#.#.#.#.#.#.#.|.|)"), ("+------------------------+") };
int main(){
	int N;
	cin>>N;
	for(int i=1;N>0&&i<5;N--,i++)sto[i][1]='O';
	if(N>0){
		int cnt=N/3,mod=N%3;
		for(int i=1;i<5;i++){
			if(i==3)continue;
			int pos=3;
			for(int j=1;j<=cnt;pos+=2,j++)sto[i][pos]='O';
			if(mod){
				sto[i][pos]='O';
				mod--;
			}
		}
	}
	for(int i=0;i<6;i++)cout<<sto[i]<<"\n";
	return 0;
}
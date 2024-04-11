#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
	int k, q;
	cin >> k >> q;
	double p[q];
	for(int i = 0; i < q; i++){
		cin >> p[i];
		p[i] -= 0.000000001;
		p[i] /= 2000.0;

	}
	double prob[k+1];
	for(int i = 0; i <= k; i++) prob[i] = 0;
	prob[0] = 1;
	vector<double> d;
	for(int z = 0; z < 20000; z++){
		d.push_back(prob[k]);
		if(prob[k] > 0.5) break;
		double newprob[k+1];
		for(int i = 0; i <= k; i++) newprob[i] = 0;
		newprob[k] += prob[k];
		for(int i = 0; i < k; i++){
			double c = ((double)(k-i))/(double)(k);
			newprob[i+1] += c * prob[i];
			newprob[i] += (1.0-c) * prob[i];
		}
		for(int i = 0; i <= k; i++){
			prob[i] = newprob[i];
		}
	}
	for(int i = 0; i < q; i++){
		for(int j = 0; j < d.size(); j++){
			if(d[j] > p[i]){
				cout << j << endl;
				break;
			}
		}
	}
	//probability has 
}
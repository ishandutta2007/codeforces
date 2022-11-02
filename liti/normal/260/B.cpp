#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char **argv)
{
	string s;
	cin >> s;
	vector<string> result;
	vector<int> r;
	int m[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
	char ptr[10] = {1,1,0,1,1,0,1,1,1,1};
	for(unsigned int i =0 ; i < s.length() - 9 ; i++){
		string tmp ="";
		for(int j = 0 ; j < 10 ; j++){
			if ( ptr[j] == 0 && s[i + j] != '-' )
				break;
			if ( ptr[j] == 1 && s[i + j] == '-' )
				break;
			tmp += s[i+j];
		}
		if ( tmp.length() < 10 )
			continue;
		int day = (tmp[0] - 48)*10 + (tmp[1] - 48);
		int month = (tmp[3] - 48)*10 + (tmp[4] - 48);
		int year  = (tmp[6] - 48)*1000 + (tmp[7] - 48)*100 + (tmp[8] - 48)*10 + (tmp[9] - 48);
		if ( month > 12 || month == 0 ) 
			continue;
		if ( year < 2013 || year > 2015 )
			continue;
		if ( day > m[month-1] || day == 0 )
			continue;
			
		bool m = false;
		for(unsigned int j = 0 ;j < r.size() ; j++){
			if ( result[j] == tmp ){
				r[j]++;
				m = true;
				break;
			}
		}
		if ( m == false ){
			result.push_back(tmp);
			r.push_back(1);
		}
		
	}
	
	int max = 0;
	int maxId = -1;
	for(int i = 0 ;i < r.size(); i++){
		if ( r[i] > max ){
			max = r[i];
			maxId = i;
		}
	}
	cout << result[maxId] << endl;
	return 0;
}
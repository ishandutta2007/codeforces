#include <cstdio>
#include <string>
using namespace std;

const int Maxn = 40;

const string P[Maxn] = {"Washington", "Adams", "Jefferson", "Madison", "Monroe", "Adams", "Jackson", "Van Buren", "Harrison", "Tyler",
			     		  "Polk", "Taylor", "Fillmore", "Pierce", "Buchanan", "Lincoln", "Johnson", "Grant", "Hayes", "Garfield",
			      		  "Arthur", "Cleveland", "Harrison", "Cleveland", "McKinley", "Roosevelt", "Taft", "Wilson", "Harding", "Coolidge",
			    		  "Hoover", "Roosevelt", "Truman", "Eisenhower", "Kennedy", "Johnson", "Nixon", "Ford", "Carter", "Reagan"};

int main()
{
	int a; scanf("%d", &a);
	printf("%s\n", P[a - 1].c_str());
	return 0;
}
#include <iostream>
#include <cassert>

using namespace std;

int main()
{
	int N;
    cin >> N;

	int zeros = 0;

	string lmult = "";

    while(N--) {
		string s;
		cin >> s;

		if (s == "0") {
			cout << "0" << endl;
			return 0;
		}

        int nr1 = 0, nr0 = 0;
        for (unsigned int i = 0; i < s.size(); i++) {
			if (s[i] == '0') nr0++;
			if (s[i] == '1') nr1++;
        }

//		cerr << "*" << s << "* " << nr0 << " " << nr1 << endl;

        if (nr1 <= 1 && nr0 + nr1 == s.size()) {
			zeros += nr0;
        } else {
			assert(lmult == "");
        	lmult = s;
        }
    }

    if (lmult == "") cout << 1;
	else cout << lmult;

	while (zeros--) cout << 0;
	cout << endl;
    return 0;
}
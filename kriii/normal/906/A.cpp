#include <stdio.h>

int N; char op[5],str[100100];
int can[26];

int main()
{
	scanf ("%d",&N); N--;
	int c = 0, know = 0;
	for (int i=0;i<26;i++) can[i] = 1;

	while (N--){
		scanf ("%s %s",op,str);
		if (op[0] == '!'){
			bool tmp[26] = {0,};
			for (int i=0;str[i];i++) tmp[str[i]-'a'] = 1;
			for (int i=0;i<26;i++) if (can[i] && !tmp[i]) can[i] = 0;
			if (know) c++;
		}
		else if (op[0] == '.'){
			for (int i=0;str[i];i++) can[str[i]-'a'] = 0;
		}
		else if (op[0] == '?'){
			can[str[0]-'a'] = 0;
			if (know) c++;
		}

		int v = 0;
		for (int i=0;i<26;i++) v += can[i];
		if (v == 1) know = 1;
	}

	printf ("%d\n",c);

	return 0;
}
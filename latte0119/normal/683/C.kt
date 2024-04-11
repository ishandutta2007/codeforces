import java.util.*

fun main(args: Array<String>){
	val cin=Scanner(System.`in`);

	var cnt=Array<Int>(2100){i->0};

	var N=cin.nextInt();
	var A=Array<Int>(N){i->0};
	for(i in A.indices){
		A[i]=cin.nextInt()+1000;
		cnt[A[i]]++;
	}

	var M=cin.nextInt();
	var B=Array<Int>(M){i->0};
	for(i in B.indices){
		B[i]=cin.nextInt()+1000;
		cnt[B[i]]++;
	}

	var L=0;
	var C=Array<Int>(2100){i->0};

	for(i in 0..2100-1){
		if(cnt[i]==1){
			C[L]=i;
			L++;
		}
	}

	print(L);
	for(i in 0..L-1){
		print(" ${C[i]-1000}");
	}
	println("");
}
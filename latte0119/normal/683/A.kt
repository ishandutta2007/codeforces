import java.util.*

fun main(args: Array<String>){
	val cin=Scanner(System.`in`);

	val a=cin.nextInt();
	val x=cin.nextInt();
	val y=cin.nextInt();

	if(x<0||x>a||y<0||y>a){
		println("2");
	}
	else if(x==a||y==a||x==0||y==0){
		println("1");
	}
	else{
		println("0");
	}
}
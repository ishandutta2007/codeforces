import java.util.*;

public class Sth{
        public static void main(String[] argc){
            Scanner sc = new Scanner(System.in);
            int n = sc.nextInt();
            String s = sc.next();
            int sz = s.length();
            String vow = "aeoiuy";
            int cnt = 0;
            if(vow.indexOf(s.charAt(0)) != -1){
                cnt = 1;
            }
			else{
				System.out.print(s.charAt(0));
			}
            for(int i = 1; i < sz; i++){
                if(vow.indexOf(s.charAt(i)) == -1){
                    if(cnt >= 2){
						if(cnt == 2 && (s.charAt(i-1) == 'e' || s.charAt(i-1) == 'o')){
							System.out.print(s.charAt(i-1));
							System.out.print(s.charAt(i-1));
						}
						else{
							System.out.print(s.charAt(i-1));
						}
                    }
					else if(cnt == 1){
						System.out.print(s.charAt(i-1));
					}
                    System.out.print(s.charAt(i));
                    cnt = 0;
                }
                else{
                    if(s.charAt(i) == s.charAt(i-1)){
                        cnt++;
                    }
                    else{
                        if(cnt >= 2){
                            if(cnt == 2 && (s.charAt(i-1) == 'e' || s.charAt(i-1) == 'o')){
                                System.out.print(s.charAt(i-1));
                                System.out.print(s.charAt(i-1));
                            }
                            else{
                                System.out.print(s.charAt(i-1));
                            }
                        }
                        else if(cnt == 1){
                            System.out.print(s.charAt(i-1));
                        }
                        cnt = 1;
                    }
                }
            }
			if(cnt >= 2){
				if(cnt == 2 && (s.charAt(n-1) == 'e' || s.charAt(n-1) == 'o')){
					System.out.print(s.charAt(n-1));
					System.out.print(s.charAt(n-1));
				}
				else{
					System.out.print(s.charAt(n-1));
				}
            }
			else if(cnt == 1){
				System.out.print(s.charAt(n-1));
			}
        }
}
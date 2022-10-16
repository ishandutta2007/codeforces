
import java.util.*;
import java.io.*;

public class A63 {
    private static BufferedReader       in;
    private static PrintWriter  out;
    
    public static void main (String [] args) throws IOException {
        in = new BufferedReader (new InputStreamReader (System.in));
        out = new PrintWriter (System.out, true);
        
        int N = Integer.parseInt (in.readLine ());
        
        Person [] people = new Person [N];
        StringTokenizer st;
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer (in.readLine());
            people [i] = new Person (st.nextToken(), st.nextToken(), i);
        }
        Arrays.sort (people);
        for (Person p : people)
            out.println (p);
        out.close();
        System.exit (0);
    }
    
    static class Person implements Comparable <Person> {
        public int idx;
        public String name, position;
        
        public Person (String name, String position, int idx) {
            this.name = name;
            this.position = position;
            this.idx = idx;
        }
        
        public int compareTo (Person other) {
            int rank1 = 0, rank2 = 0;
            if (this.position.equals ("captain")) rank1 = 0;
            if (this.position.equals ("man")) rank1 = 1;
            if (this.position.equals ("woman") ||
                    this.position.equals ("child")) rank1 = 2;
            if (this.position.equals ("rat")) rank1 = 3;
            
            if (other.position.equals ("captain")) rank2 = 0;
            if (other.position.equals ("man")) rank2 = 1;
            if (other.position.equals ("woman") ||
                    other.position.equals ("child")) rank2 = 2;
            if (other.position.equals ("rat")) rank2 = 3;
            
            return rank1 == rank2 ? idx - other.idx : rank2 - rank1;
        }
        
        public String toString () {
            return name;
        }
    }
}
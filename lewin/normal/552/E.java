import java.io.*;
import java.util.*;

import javax.script.*;

public class vanyabrackets {
  private static InputReader in;
  private static PrintWriter out;

  public static void main(String[] args) throws Exception {
    in = new InputReader(System.in);
    out = new PrintWriter(System.out, true);

    char[] c = in.next().toCharArray();
    int[] pos = new int[20];
    int idx = 0;
    pos[idx++] = -1;
    for (int i = 0; i < c.length; i++) {
      if (c[i] == '*')
        pos[idx++] = i;
    }
    pos[idx++] = c.length;

    long max = 0;
    for (int i = 0; i < idx; i++) {
      for (int j = i + 1; j < idx; j++) {
        max = Math.max(max, eval(pos[i] + 1, pos[j] - 1, c));
      }
    }
    out.println(max);
    out.close();
    System.exit(0);
  }

  public static long eval(int bf, int bt, char[] c) throws ScriptException {
    StringBuilder expr = new StringBuilder();
    for (int i = 0; i < bf; i++) expr.append(c[i]);
    expr.append("(");
    for (int i = bf; i <= bt; i++) expr.append(c[i]);
    expr.append(")");
    for (int i = bt + 1; i < c.length; i++) expr.append(c[i]);

    return evalInfix(expr.toString());

  }
  // code modified from here: http://willcode4beer.com/design.jsp?set=evalInfix
  public static long evalInfix(String infix) {
    return evaluatePostfix(convert2Postfix(infix));
  }

  public static String convert2Postfix(String infixExpr) {
    char[] chars = infixExpr.toCharArray();
    Stack<Character> stack = new Stack<Character>();
    StringBuilder out = new StringBuilder(infixExpr.length());

    for (char c : chars) {
      if (c == '*' || c == '+') {
        while (!stack.isEmpty() && stack.peek() != '(') {
          if (stack.peek() == '*' || c == '+') {
            out.append(stack.pop());
          } else {
            break;
          }
        }
        stack.push(c);
      } else if (c == '(') {
        stack.push(c);
      } else if (c == ')') {
        while (!stack.isEmpty() && stack.peek() != '(') {
          out.append(stack.pop());
        }
        if (!stack.isEmpty()) {
          stack.pop();
        }
      } else {
        out.append(c);
      }
    }
    while (!stack.empty()) {
      out.append(stack.pop());
    }
    return out.toString();
  }

  public static long evaluatePostfix(String postfixExpr) {
    char[] chars = postfixExpr.toCharArray();
    Stack<Long> stack = new Stack<Long>();
    for (char c : chars) {
      if (c != '+' && c != '*') {
        stack.push((long) (c - '0'));
      } else if (c == '*' || c == '+') {
        long op1 = stack.pop();
        long op2 = stack.pop();
        long result;
        switch (c) {
          case '*':
            result = op1 * op2;
            stack.push(result);
            break;
          case '+':
            result = op1 + op2;
            stack.push(result);
            break;
        }
      }
    }
    return stack.pop();
  }

  static class InputReader {
    public BufferedReader reader;
    public StringTokenizer tokenizer;

    public InputReader(InputStream stream) {
      reader = new BufferedReader(new InputStreamReader(stream), 32768);
      tokenizer = null;
    }

    public String next() {
      while (tokenizer == null || !tokenizer.hasMoreTokens()) {
        try {
          tokenizer = new StringTokenizer(reader.readLine());
        } catch (IOException e) {
          throw new RuntimeException(e);
        }
      }
      return tokenizer.nextToken();
    }

    public int nextInt() {
      return Integer.parseInt(next());
    }
  }


}
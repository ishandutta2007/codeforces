//Not my code: https://codeforces.com/blog/entry/98042

var n,k,x,ss,top,ttop,tt:int64;
    i,j,t:longint;
    s:ansistring;
    c:char;
    a:array[0..20000]of int64;
    out:ansistring;
    
begin
  out := '';
  readln(t);
  for t:=1 to t do
  begin
    readln(n,k,x);
    readLn(s);
    top:=0;ss:=0;dec(x);
    for i:=1 to length(s) do
      if (s[i]='a') and (ss<>0) then
      begin
        inc(top);
        a[top]:=k*ss;
        ss:=0;
      end else
      if s[i]='*' then inc(ss);
    if ss<>0 then
    begin
      inc(top);
      a[top]:=k*ss;
    end;
    ss:=x;
    for i:=top downto 1 do
    begin
      tt:=a[i];
      a[i]:=ss mod (tt+1);
      ss:=ss div (tt+1);
    end;
    ttop:=0;ss:=0;
    for i:=1 to length(s) do
    begin
      if (s[i]='a') and (ss<>0) then
      begin
        inc(ttop);
        for j:=1 to a[ttop] do 
          out+='b';
        ss:=0;
      end else
      if s[i]='*' then inc(ss);
      if s[i]='a' then 
          out += 'a';
    end;
    if s[length(s)]='*' then
      for i:=1 to a[top] do 
          out+='b';
    out+=chr(13);
  end;
  writeLn(out);
end.
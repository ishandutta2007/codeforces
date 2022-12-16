var n,i,c,ans:longint;s:ansistring;
begin
  readln(n);
  readln(s);
  s:=s+'X';
  for i:=1 to n+1 do
  begin
    if s[i]='x'then inc(c)
    else
    begin
      if c>=3 then inc(ans,c-2);
      c:=0;
    end;
  end;
  writeln(ans);
end.
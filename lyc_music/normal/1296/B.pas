var t,i1,s,i,ans,tp:longint;st:ansistring;
begin
  readln(t);
  for i1:=1 to t do
  begin
    readln(s);ans:=0;
    while s>0 do
    begin
      str(s,st);tp:=(ord(st[1])-ord('0'));
      for i:=1 to length(st)-1 do tp:=tp*10;
      s:=s-tp+tp div 10;
      ans:=ans+tp;
    end;
    writeln(ans);
  end;
end.
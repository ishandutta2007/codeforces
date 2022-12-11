program Project1;

{$APPTYPE CONSOLE}

var
  st,ans:string;
  i,pk,dog:LongInt;
begin
  dog:=0;
  Readln(st);
  pk:=1;
  ans:='';
  for i:=1 to Length(st) do
  begin
    if (st[i]='d') and (st[i+1]='o') and (st[i+2]='t') and (i<>1) and (i+2<>Length(st)) then
      begin
        pk:=pk+3;
        ans:=ans+'.';
      end;
    if (st[i]='a') and (st[i+1]='t') and (i<>1) and (i+1<>Length(st)) and (dog=0) then
      begin
        pk:=pk+2;
        ans:=ans+'@';
        Inc(dog);
      end;
    if pk=i then
      begin
        ans:=ans+st[i];
        inc(pk);
      end;
  end;
  Writeln(ans);
end.
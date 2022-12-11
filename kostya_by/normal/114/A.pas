program project1;

var
   l,k,i : int64;
begin
     read(k,l);
     i:=0;
     while l <> 1 do begin
           if l mod k <> 0 then begin
              writeln('NO');
              halt(0);
           end;
           l:=l div k;
           inc(i);
     end;
     writeln('YES');
     writeln(i - 1);
end.
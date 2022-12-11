program project1;

var
   t : array[1..300] of int64;
   i,l:longint;
   ans : int64;
   s : ansistring;
begin
     for i:=1 to 300 do t[i]:=0;
     readln(s);
     l:=length(s);
     for i:=1 to l do begin
         inc(t[ord(s[i])]);
     end;
     ans:=0;
     for i:=1 to 300 do begin
         if t[i]>0 then begin
            ans:=ans+sqr(t[i]);
         end;
     end;
     writeln(ans);
end.
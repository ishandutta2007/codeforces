program project1;

var
sum : array[65..67] of integer;
h : array[65..67] of integer;
i,j,y:longint;
st,ans:string;
begin
     for i:=65 to 67 do sum[i]:=0;
     for i:=65 to 67 do h[i]:=i;
     for i:=1 to 3 do begin
         readln(st);
         if st[2]='>' then inc(sum[ord(st[1])]) else inc(sum[ord(st[3])]);
     end;
     for i:=65 to 67 do begin
         for j:=65 to 67 do begin
             if sum[i]<sum[j] then begin
                y:=sum[i];
                sum[i]:=sum[j];
                sum[j]:=y;
                y:=h[i];
                h[i]:=h[j];
                h[j]:=y;
             end;
         end;
     end;
     ans:='';
     for i:=65 to 67 do begin
         if sum[i]<>i-65 then begin ans:='Impossible'; break; end else begin
            ans:=ans+chr(h[i]);
         end;
     end;
     writeln(ans);
end.